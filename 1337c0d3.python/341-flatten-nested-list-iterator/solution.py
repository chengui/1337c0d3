from __future__ import print_function
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

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
        """
        for i in nestedList:
            if isinstance(i, list):
                self.__flat = self.flat(i)
            else:
                self.__flat.append(i)
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
    i, v = NestedIterator(lst), []
    while i.hasNext(): v.append(i.next())
    print(v)
