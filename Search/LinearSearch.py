def linear( target, list ):
    """ returns the position of target,
    if not found returns -1"""
    position = 1
    while position <= len(list):
        if target == list[position]:
            return position
        position += 1
    return -1
