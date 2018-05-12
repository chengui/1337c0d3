#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int tmp = 0;
        int ilow = 0, ihigh = n - 1;
        int jlow = 0, jhigh = n - 1;

        while (ilow < ihigh) {
            if ((A[ilow] > 0) != (A[ihigh] > 0)) {
                if ((A[ilow] > 0) > (A[ihigh] > 0)) {
                    tmp = A[ilow];
                    A[ilow] = A[ihigh];
                    A[ihigh] = tmp;
                }
                ilow++;
                ihigh--;
            } else {
                if ((A[ilow] > 0) > 0)
                    ihigh--;
                else
                    ilow++;
            }
        }

        while (jlow < jhigh) {
            if ((A[jlow] >> 1) != (A[jhigh] >> 1)) {
                if ((A[jlow] >> 1) > (A[jhigh] >> 1)) {
                    tmp = A[jlow];
                    A[jlow] = A[jhigh];
                    A[jhigh] = tmp;
                }
                jlow++;
                jhigh--;
            } else {
                if ((A[jlow] >> 1) > 0)
                    jhigh--;
                else
                    jlow++;
            }
        }

    }
};

int main() {
    int A[] = {2, 0, 2, 1, 1, 0};
    Solution solu = Solution();
    solu.sortColors(A, sizeof(A)/sizeof(int));
    for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
        cout << A[i] << ", ";
    }
    cout << endl;
}
