import numpy as np 
import matplotlib.pyplot as plt


# Função a ser usada no algoritmo
def f(x):
    return (np.exp(x)/2 -1 + -2*np.cos(x))    
     
   
#Entradas a e b 
a = float(input(""))
b = float(input(""))

# condição para que se f(a) vezes f(b) forem negativos essa condição deve aceitar = True
if (f(a)*f(b) < 0):

    print("f({:.0f})= {:.2f}\nf({:.0f})= {:.2f}".format(a,f(a),b,f(b)))

    # se entra a for maior que b, o b<a fica a>b
    if(a>b):
      b,a = a,b

    """
    cria-se um while loop que para somente se o 
    intervalo entre os 2 forem menores que 0.1 
    """
    interval = (b - a)
    
    while(interval >= 0.1):

        media = (a+b)/2

        root = media

        if (f(root)* f(a) < 0):

            b = root
    
        elif (f(root) * f(b) < 0):

            a = root

        interval = (b - a)
        
    # Printa a resposta do intervalo
    print("\nA equação tem, pelo menos, uma solução neste intervalo: {}".format([a,b]))

    # Input para permitir a visualização do gráfico, input dado em letra maiuscula com o metodo upper
    resposta = input("\nDeseja visualizar o gráfico da função? (sim ou não) ").upper()
    # Condição para que se a resposta for SIM mostre o gráfico
    if (resposta=='SIM'):
        x = np.linspace(-14, 3, num=10000)
        fig, ax = plt.subplots()
        # Titulo do gráfico
        ax.set_title("Gráfico da Função no Intervalo")
        ax.plot(x, f(x))
        ax.set_aspect('auto')
        # Mostra as linhas (grid) no gráfico
        ax.grid(True, which='both')
        ax.axhline(y=0, color='k')
        ax.axvline(x=0, color='k')
        fig.set_figheight(5)
        fig.set_figwidth(9)


        # Seta as coordenadas(localização
        # )
        ax.annotate("Intervalo = [%.2f, %.2f]" %(a,b), xy=(a,0),size=8, xycoords='data', xytext=(a, 0.8),arrowprops=dict(arrowstyle = "->",connectionstyle="arc3"),
            )
        # plt.show() exibe o gráfico
        plt.show()
    
# Caso a condição de f(a) vezes f(b) forem positivos dá que não é possivel afirmar que existe solução
else:
    print('\nNão é possível afirmar que existe solução neste intervalo, tente outros dois números\n')
