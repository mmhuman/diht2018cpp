//------------------------------------------------------------------------------
//! Struct line of text: string + length of this string
//------------------------------------------------------------------------------

struct line {
    char* str;
    size_t len;

    //------------------------------------------------------------------------------
    //! Construct line with specified length
    //!
    //! @param [in]  len length
    //------------------------------------------------------------------------------

    line(int len): len(len) {
        str = new char[len];
    }

    //------------------------------------------------------------------------------
    //! Construct line from another line
    //!
    //! @param [in] a line
    //------------------------------------------------------------------------------

    line(const line& a): len(a.len) {
        str = new char[len];
        memcpy(str, a.str, len);
    }

};


//------------------------------------------------------------------------------
//! Check if char is punctuation mark
//!
//! @param [in] c character
//!
//! @return boolean
//------------------------------------------------------------------------------

bool is_punctuation_mark(char c) {
    return  c == '.' || c == '?' || c == '!' || c == ',' || c == ':' || c == ';' ||
            c == '(' || c == ')' || c == '\'' || c == '[' || c == ']';
}

//------------------------------------------------------------------------------
//! Compare lines a and b from the beginning
//!
//! @param [in] a reference to line a
//! @param [in] b reference to line b 
//!
//! @return a < b
//------------------------------------------------------------------------------

bool line_comp(const line& a, const line& b) {
    size_t b_pos = 0;
    for (size_t a_pos = 0; a_pos < a.len; ++a_pos) {
        if (is_punctuation_mark(a.str[a_pos]))
            continue;
        while (b_pos < b.len && is_punctuation_mark(b.str[b_pos]))
            ++b_pos;
        if (b_pos == b.len)
            return false;
        if (a.str[a_pos] != b.str[b_pos]) {
            return a.str[a_pos] < b.str[b_pos];
        }
        ++b_pos;
    }
    return b_pos < b.len;
}

//------------------------------------------------------------------------------
//! Compare lines a and b from the end
//!
//! @param [in] a reference to line a
//! @param [in] b reference to line b 
//!
//! @return a < b
//------------------------------------------------------------------------------


bool line_rev_comp(const line& a, const line& b) {
    int b_pos = static_cast<int>(b.len) - 1;
    for (int a_pos = static_cast<int>(a.len) - 1; a_pos >= 0; --a_pos) {
        if (is_punctuation_mark(a.str[a_pos]))
            continue;
        while (b_pos >= 0 && is_punctuation_mark(b.str[b_pos]))
            --b_pos;
        if (b_pos < 0)
            return false;
        if (a.str[a_pos] != b.str[b_pos]) {
            return a.str[a_pos] < b.str[b_pos];
        }
        --b_pos;
    }
    return b_pos >= 0;
}
