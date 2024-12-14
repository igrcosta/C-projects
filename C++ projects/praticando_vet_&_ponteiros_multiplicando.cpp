#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arro{1,2,3,4,5,6};
    vector <int> arrn;

    int *p=&arro[0];
    int mult;

    for(p;p < &arro[arro.size()];p++){
        mult = *p * 2;
        arrn.push_back(mult);
        }
        //impressão dos vetores
        p=&arro[0];

        cout << "Vetor 1:" << endl;

        for(p; p < &arro[arro.size()];p++){
            cout << *p << ", ";
        }

        cout << endl << endl;
        cout << "Vetor 2, multiplicando os elementos de vetor 1:" << endl;

        for(int i = 0; i < arrn.size(); i++){
            cout << arrn[i] << ", ";
        }
        return 0;
    }
