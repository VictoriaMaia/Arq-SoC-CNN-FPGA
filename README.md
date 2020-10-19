# Código fonte do Trabalho de Conclusão de Curso intitulado: 

## Um gerador de arquiteturas SoC para execução de Redes Neurais Convolucionais em FPGAs.


- Código do script gerador de arquivos de cabeçalho esta no arquivo **inicializando.py**  

- Código C++ com as intruções das camadas de convolução, maxpool e fully conected estão na pasta **src/**

- Arquivos de cabeçalho gerados pelo script estão na pasta **include/**

- Rede CNN desenvolvida para testar o sistema esta no arquivo **CNN_MNIST.ipynb**

A rede em C++ utiliza funções do opencv, então antes de compilar instale o opencv2.

Para compilar a rede C++, execute o seguinte comando no terminal :
    
        $ make

Para executar a rede C++, execute:

        $ ./app caminhoDaImagem



