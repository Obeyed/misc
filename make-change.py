""" Run tests with `python3 make-change.py -v` (with verbose logging). """

BILLS = [100, 50, 20, 10, 5, 1]

def make_change(x):
    """ Given a currency with denominations of 100, 50, 20, 10, 5 and 1 write a 
    method that takes an integer amount representing the total change to make 
    and return an integer representing the smallest possible number of bills 
    to return.

    >>> [make_change(n) for n in [100, 50, 20, 10, 5, 1]]
    [1, 1, 1, 1, 1, 1]
    >>> [make_change(n) for n in [0, 1235, 100001, 2, 135]]
    [0, 15, 1001, 2, 4]
    >>> make_change(139)
    8
    """
    total, amount = (x, 0)
    for bill in BILLS:
        change  = total // bill
        amount += change
        total  -= change * bill
    return amount

if __name__ == "__main__":
    import doctest
    doctest.testmod()
