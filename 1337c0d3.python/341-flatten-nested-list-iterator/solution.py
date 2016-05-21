from __future__ import print_function
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
class NestedInteger(object):
    def __init__(self, val):
        """
        Initailize NestedInteger
        """
        if isinstance(val, list):
            self.__value = map(NestedInteger, val)
        else:
            self.__value = val

    def isInteger(self):
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        :rtype bool
        """
        return isinstance(self.__value, int)

    def getInteger(self):
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        :rtype int
        """
        return self.__value

    def getList(self):
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        :rtype List[NestedInteger]
        """
        return self.__value

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.__pointer = 0
        self.__flat = []
        self.flat(nestedList)

    def flat(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: List[Integer]
        """
        for i in nestedList:
            if i.isInteger():
                self.__flat.append(i.getInteger())
            else:
                self.__flat = self.flat(i.getList())
        return self.__flat

    def next(self):
        """
        :rtype: int
        """
        self.__pointer += 1
        return self.__flat[self.__pointer-1]

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.__pointer < len(self.__flat)

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())

if __name__ == "__main__":
    lst = [[1, 1], 2, [1, 1]]
    # lst = [1, [4,[6]]]
    lst = [NestedInteger([1,1]), NestedInteger(2), NestedInteger([1,1])]
    i, v = NestedIterator(lst), []
    while i.hasNext(): v.append(i.next())
    print(v)
