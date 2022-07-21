#include "a5-diff.h"

#define BOOL_TO_STR(b) b ? "true" : "false"

void zero_newlines(char *s)
{
	size_t max_len_s = strnlen(s, MAX_LINE_LENGTH);
	for (int i = 0; i < max_len_s; i++) {
		if (s[i] != '\n')
			continue;

		s[i] = '\0';
		if (i + 1 < max_len_s && s[i + 1] == '\r')
			s[i + 1] = '\0';

		break;
	}
}

int main(int argc, char **argv)
{
	if (argc < 3 || argc > 5) {
		fprintf(stderr, "Usage: mydiff file1 file2 -flags\n");
		return 1;
	}

	bool cleanup_close_files = false;
	bool cleanup_free_strings = false;
	int ret = 0;
	char err_msg[ERR_MSG_SIZE + 1];
	strcpy(err_msg, "unknown error\n");

	int option = -1;

	bool i_flag = false;
	bool B_flag = false;

	while ((option = getopt(argc, argv, "iB")) != -1) {
		switch (option) {
		case 'i':
			i_flag = true;
			break;

		case 'B':
			B_flag = true;
			break;
		default:
			fprintf(stderr, "WARNING: Ignoring unrecognized flag, proceeding.\n\n");
			break;
		}
	}

	/* getopt does some moving around of options in argv */
	int index_a = -1;
	int index_b = -1;
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-')
			continue;
		else if (index_a < 0)
			index_a = i;
		else if (index_b < 0)
			index_b = i;
		else
			break;
	}

	if (index_a < 0 || index_b < 0) {
		snprintf(err_msg, ERR_MSG_SIZE, "could not find files to diff\n");
		goto err_cleanup;
	}

	FILE *a = fopen(argv[index_a], "r");
	if (a == NULL) {
		snprintf(err_msg, ERR_MSG_SIZE, "could not open file %s\n", argv[index_a]);
		goto err_cleanup;
	}

	FILE *b = fopen(argv[index_b], "r");
	if (b == NULL) {
		fclose(a);
		snprintf(err_msg, ERR_MSG_SIZE, "could not open file %s\n", argv[index_b]);
		goto err_cleanup;
	}

	cleanup_close_files = true;

	long size_a = -1;
	fseek(a, 0, SEEK_END);
	size_a = ftell(a);
	fseek(a, 0, SEEK_SET);
	if (size_a < 0) {
		snprintf(err_msg, ERR_MSG_SIZE, "could not find file size of %s\n", argv[index_a]);
		goto err_cleanup;
	}

	long size_b = -1;
	fseek(b, 0, SEEK_END);
	size_b = ftell(b);
	fseek(b, 0, SEEK_SET);
	if (size_b < 0) {
		snprintf(err_msg, ERR_MSG_SIZE, "could not find file size of %s\n", argv[index_b]);
		goto err_cleanup;
	}

	if (size_a > MAX_FILE_SIZE || size_b > MAX_FILE_SIZE) {
		snprintf(err_msg, ERR_MSG_SIZE, "max file size of %d bytes exceeded\n",
			 MAX_FILE_SIZE);
		goto err_cleanup;
	}

	char *str_a = malloc(size_a + 1);
	char *str_b = malloc(size_b + 1);
	cleanup_free_strings = true;

	if (fread(str_a, 1, size_a, a) != size_a) {
		snprintf(err_msg, ERR_MSG_SIZE, "could not read file %s", argv[index_a]);
		goto err_cleanup;
	}
	fseek(a, 0, SEEK_SET);

	if (fread(str_b, 1, size_b, b) != size_b) {
		snprintf(err_msg, ERR_MSG_SIZE, "could not read file %s", argv[index_b]);
		goto err_cleanup;
	}
	fseek(b, 0, SEEK_SET);

	fprintf(stderr,
		"file a is %s, file size of a is %ld\nfile b is %s, file size of b is %ld\n\n",
		argv[index_a], size_a, argv[index_b], size_b);

	fprintf(stderr, "contents of file a:\n%s\n\n", str_a);
	fprintf(stderr, "contents of file b:\n%s\n", str_b);
	fprintf(stderr,
		"-------------------------------------------------------------------------\n");
	fprintf(stderr, "calling diff(%s, %s, i = %s, B = %s);\n", argv[index_a], argv[index_b],
		BOOL_TO_STR(i_flag), BOOL_TO_STR(B_flag));
	fprintf(stderr,
		"-------------------------------------------------------------------------\n\n\n");

	diff(a, b, i_flag, B_flag);

	fclose(a);
	fclose(b);
	cleanup_close_files = false;

cleanup:
	if (cleanup_close_files) {
		fclose(a);
		fclose(b);
	}

	if (cleanup_free_strings) {
		free(str_a);
		free(str_b);
	}

	if (ret != 0) {
		err_msg[ERR_MSG_SIZE] = '\0';
		fprintf(stderr, "\nERROR: %s\n", err_msg);
	}

	return ret;

err_cleanup:
	ret = 1;
	goto cleanup;
}
