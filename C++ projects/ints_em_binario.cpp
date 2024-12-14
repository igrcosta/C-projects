#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector <int> nums;
    int num;

    for (int i =0; i < 5; i++){
        //user insere numeros
        cin >> num;
        nums.push_back(num);
    }

    int *p = &nums[0];

    ofstream arquivoE;
    arquivoE.open("numeros.bin",ios::binary|ios::app);

    if(arquivoE.is_open()){
        for(p; p < &nums[nums.size()];p++){
            arquivoE.write((char*) p, sizeof(p));
        }
        arquivoE.close();
    } else {
    cout << "Erro ao abrir arquivo" << endl;
    return 0;
    }

    cout << "Vamos ler o arquivo!" << endl;

    ifstream arquivoL;
    arquivoL.open("numeros.bin", ios::binary);
    if (arquivoL.is_open()){

        p = &nums[0];

        for(p;p < &nums[nums.size()]; p++){
            arquivoL.read((char*) p, sizeof(p));
            cout << *p << endl;
        }
    } else {
        cout << "Erro ao abrir arquivo" << endl;
        return 0;
    }

    arquivoL. close();

    return 0;
}
