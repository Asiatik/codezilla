"""
    In MS-Paint, when we take the brush to a pixel and click,
        the color of the region of that pixel is replaced with a new selected color.
    Given a 2D screen, location of a pixel in the screen and a color,
        replace color of the given pixel and all adjacent same colored pixels
        with the given color.
"""

class Color:
    BLACK = 0
    RED = 1
    GREEN = 2
    BLUE = 3
    MAGENTA = 4
    CYAN = 5
    YELLOW = 6
    BLACK = 7

def paint_fill(screen, row, col, new_color):
    try:
        old_color = screen[row][col]s
    except IndexError:  # In case of invalid row/col or empty screen, do nothing
        return
    
    if (old_color == new_color):
        return
    else:
        paint_fill_helper(screen, row, col, old_color, new_color)

def paint_fill_helper(screen, row, col, old_color, new_color):
    if (not is_in_bounds(screen, row, col)):
        return
    if (screen[row][col] != old_color):
        return

    screen[row][col] = new_color

    paint_fill_helper(screen, row-1, col, old_color, new_color) # Up
    paint_fill_helper(screen, row+1, col, old_color, new_color) # Down
    paint_fill_helper(screen, row, col-1, old_color, new_color) # Left
    paint_fill_helper(screen, row, col+1, old_color, new_color) # Right

def is_in_bounds(screen, row, col):
    return (0 <= row < len(screen)) and (0 <= col < len(screen[0]))

if __name__ == "__main__":
    screen = [
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 0, 0],
                [1, 0, 0, 1, 1, 0, 1, 1],
                [1, 2, 2, 2, 2, 0, 1, 0],
                [1, 1, 1, 2, 2, 0, 1, 0],
                [1, 1, 1, 2, 2, 2, 2, 0],
                [1, 1, 1, 1, 1, 2, 1, 1],
                [1, 1, 1, 1, 1, 2, 2, 1],
                [1, 1, 1, 1, 1, 1, 1, 1]
             ]
    assert(is_in_bounds([[1]], 0, 0))
    assert(not is_in_bounds([], 0, 0))
    assert(not is_in_bounds([[]], 0, 0))
    assert(is_in_bounds(screen, 0, 1))
    assert(not is_in_bounds(screen, -1, 1))
    assert(not is_in_bounds(screen, 0, -1))
    assert(not is_in_bounds(screen, 8, 8))
    assert(is_in_bounds(screen, 8, 7))

    expected_screen1 = [
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 0, 0],
                [1, 0, 0, 1, 1, 0, 1, 1],
                [1, 3, 3, 3, 3, 0, 1, 0],
                [1, 1, 1, 3, 3, 0, 1, 0],
                [1, 1, 1, 3, 3, 3, 3, 0],
                [1, 1, 1, 1, 1, 3, 1, 1],
                [1, 1, 1, 1, 1, 3, 3, 1],
                [1, 1, 1, 1, 1, 1, 1, 1]
             ]
    assert(screen != expected_screen1)  # Before fill
    paint_fill(screen, 4, 3, Color.BLUE)
    assert(screen == expected_screen1)  # After fill

    expected_screen2 = [
                [1, 1, 1, 1, 1, 1, 1, 1],
                [1, 1, 1, 1, 1, 1, 0, 0],
                [1, 1, 1, 1, 1, 0, 1, 1],
                [1, 3, 3, 3, 3, 0, 1, 0],
                [1, 1, 1, 3, 3, 0, 1, 0],
                [1, 1, 1, 3, 3, 3, 3, 0],
                [1, 1, 1, 1, 1, 3, 1, 1],
                [1, 1, 1, 1, 1, 3, 3, 1],
                [1, 1, 1, 1, 1, 1, 1, 1]
             ]
    assert(screen != expected_screen2)
    paint_fill(screen, 2, 1, Color.RED)
    assert(screen == expected_screen2)

    paint_fill(screen, 0, 0, Color.RED)
    assert(screen == screen)    # Test trying to paint same color
