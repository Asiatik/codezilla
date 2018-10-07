import collections
import string

"""
    Returns True if two strings are anagrams of each other.
    An anagram is a string that shares all the same characters
        as another string in any order
    This function will be case-insensitive and ignore spaces
"""
def is_anagram(a, b):
    a_lower = a.lower()
    b_lower = b.lower()
    a_char_count = collections.Counter(a_lower)
    b_char_count = collections.Counter(b_lower)
    
    for c in string.ascii_lowercase + string.digits:
        if (a_char_count[c] != b_char_count[c]):
            return False

    return True

if __name__ == "__main__":
    assert(is_anagram("aaa", "aaa"))
    assert(is_anagram("", ""))
    assert(is_anagram("Hello World", "dehllloorw"))
    assert(is_anagram("Hello World 42", "24de hll loorw"))
