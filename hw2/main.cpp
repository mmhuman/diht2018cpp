#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sys/stat.h>

#include "lines.h"

using std::vector;

enum {
	E_FILEOPEN
};

void read_book(char* book_filename, vector <line>* text_lines) {
	assert(text_lines != nullptr);
	FILE* file = fopen(book_filename, "r");
	if (file == nullptr) {
		printf("Can't open this file\n");
		exit(E_FILEOPEN);
	}

	struct stat file_stat;
	fstat(fileno(file), &file_stat);	
	size_t text_len = file_stat.st_size;
	char* text = new char[text_len + 1];
	assert(fread(text, sizeof(char), text_len, file) == text_len);
	text[text_len++] = '\n';

	const int MAX_LINE_LEN = (1 << 12);
	char buffer[MAX_LINE_LEN];
	size_t buffer_ptr = 0;
	for (size_t i = 0; i < text_len; ++i) {
		if (text[i] == '\n') {	
			buffer[buffer_ptr] = 0;
			text_lines->emplace_back(buffer_ptr + 1);
			strcpy(text_lines->back().str, buffer);
			buffer_ptr = 0;
		} else {
			assert(buffer_ptr < MAX_LINE_LEN);
			buffer[buffer_ptr++] = text[i];
		}
	}

	delete text;
	fclose(file);
}

void print_lines(const char* filename, vector <line>* text_lines, bool flag_delete_empty_strings) {
	assert(text_lines != nullptr);
	FILE* file = fopen(filename, "w");
	assert(file != nullptr);
	for (size_t i = 0; i < text_lines->size(); ++i) {
		if (flag_delete_empty_strings && (*text_lines)[i].len < 3)
			continue;
		fprintf(file, "%s\n", (*text_lines)[i].str);
	}
	fclose(file);
}


int main() {
	char book_filename[1024];
	printf("Enter book file name:\n");
	scanf("%s", book_filename);

	vector <line> text_lines;
	read_book(book_filename, &text_lines);

	print_lines("original_text.txt", &text_lines, false);

	sort(text_lines.begin(), text_lines.end(), line_comp);
	print_lines("sorted_text.txt", &text_lines, true);

	sort(text_lines.begin(), text_lines.end(), line_rev_comp);
	print_lines("rhymes_dictionary.txt", &text_lines, true);

	return 0;
}