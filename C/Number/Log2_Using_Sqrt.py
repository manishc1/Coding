def log2(x):
    if x <= 2:
        return 1
    y = sqrt(x)
    if (y*y != x):
        return log2(x / 2) + 1
    else:
        return 2*log2(y)