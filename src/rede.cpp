#ifndef BIBLIOTECAS
#define BIBLIOTECAS
#include "iniciarBiblio.h"
#endif

#include "iniciarFuncs.h"

double timeDenses[4];

int main( int argc, char** argv ){

    if(argc != 2){
        cout << "Precisa de apenas uma imagem para o código funcionar" << endl;
        return -1;
    }
    
    Mat entrada = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    
    if(! entrada.data){
        cout <<  "Could not open or find the image" << argv[1] << endl ;
        return -1;
    }

    Mat in;
    entrada.convertTo(in, CV_32FC1);

    in = in/255;

    // convolução
    vector <Mat> resultado_convolucao;
    
    resultado_convolucao.push_back(camadaConvolucao(in, 0));
    resultado_convolucao.push_back(camadaConvolucao(in, 1));
    resultado_convolucao.push_back(camadaConvolucao(in, 2));
    resultado_convolucao.push_back(camadaConvolucao(in, 3));
    

    // maxpool e flatten
    vector <float> result_pool0, result_pool1, result_pool2, result_pool3;
    vector <double> flatten;

    result_pool0 = camadaMaxPool(resultado_convolucao[0]);
    result_pool1 = camadaMaxPool(resultado_convolucao[1]);
    result_pool2 = camadaMaxPool(resultado_convolucao[2]);
    result_pool3 = camadaMaxPool(resultado_convolucao[3]);

    for(unsigned int i = 0; i < result_pool0.size(); i++){
        flatten.push_back(result_pool0[i]);
        flatten.push_back(result_pool1[i]);
        flatten.push_back(result_pool2[i]);
        flatten.push_back(result_pool3[i]);
    }

    camadas_densas(flatten);        

    return 0;
}