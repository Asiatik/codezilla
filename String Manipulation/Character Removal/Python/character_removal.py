"""
    Remove all occurences of char to_remove from string s
"""
def remove_character(s, to_remove):    
    result = ""
    for c in s:
        if c != to_remove:
            result += c
    return result

if __name__ == "__main__":
    assert(remove_character("Hello World", 'o') == "Hell Wrld")
    assert(remove_character("Hello World", 'l') == "Heo Word")
    assert(remove_character("Hello World", 'a') == "Hello World")
    assert(remove_character("", 'a') == "")
    assert(remove_character("Hello World", '') == "Hello World")
