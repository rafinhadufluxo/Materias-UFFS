#GITHUB : mazarafa7 (codigo disponivel)
#autor: rafaelle Arruda
#email: arruda.rafa.ra@gmail.com

import turtle
import random
window=turtle.Screen()
rafa =[[0,2,3],[5,6,7],[8,9,10],0]#elementos do reset, resposta

#TELA DO JOGO
wn = turtle.Screen()
wn.bgcolor("white")
wn.title("Jogo Simples em Turtle (@mazarafa by)")

def reset(): #Elemento adicionado para facilitar índices
    rafa[0][0]=0
    rafa[0][1]=2
    rafa[0][2]=3
    rafa[1][0]=4
    rafa[1][1]=5
    rafa[1][2]=6
    rafa[2][0]=7
    rafa[2][1]=8
    rafa[2][2]=9
    rafa[3]=0


def fim(): #fim de jogo de quem ganha.
    turtle.clear()
    move(0,0,0)
    if (-1)**rafa[3]==-1:
        turtle.write('X Ganhou!',False,'center',("Arial", 30, "normal"))
        reset()
        window.onclick(begin)
        window.listen()
    else:
        turtle.write('0 Ganhou!',False,'center',("Arial", 30, "normal"))
        reset()
        window.onclick(begin)
        window.listen()


def lula():# lateral
    for i in range(3):
        if rafa[0][i]==rafa[1][i]==rafa[2][i]:
            return True
        elif rafa[i][0]==rafa[i][1]==rafa[i][2]:
            return True
    return False

def check():#diagonal
    if lula() or rafa[0][0] == rafa[1][1] == rafa[2][2] or rafa[0][2] == rafa [1][1]== rafa [2][0]:
        return True
    
    elif rafa[3]==9: #caso de fim empatado as jogadas
        turtle.clear()
        move(0,0,0)
        turtle.color('black')
        turtle.write('Empate!',False,'center',("Arial", 50, "normal"))
        reset()
        window.onclick(begin)
        window.listen()
    else:
        return False
    
def dic(lin,col): #linha e coluna do tabuleiro e suas posições
    if col==0:
        x=-200
    elif col==1:
        x=0
    elif col==2:
        x=200
    if lin==0:
        y1=200
        y2=125
    elif lin==1:
        y1=0
        y2=-75
    elif lin==2:
        y1=-200
        y2=-275
    if (-1)**rafa[3]==-1:
        return (x,y1,45)
    elif(-1)**rafa[3]==1:
        return (x,y2,0)

def draw(lin,col): #linha e coluna, movedo a caneta
    tup=dic(lin,col)#acrescentando o X ou 0 no tabuleiro
    if (-1)**rafa[3]==-1: # desenhando o X
        move(tup[0],tup[1],tup[2])    
        turtle.pencolor('Blue')
        for i in range(4):
            turtle.forward(75)
            turtle.backward(75)
            turtle.right(90)        
    elif(-1)**rafa[3]==1:
        move(tup[0],tup[1],tup[2])
        turtle.pencolor('red')
        turtle.circle(75) #desenha o circulo  

def decode(x,y):#posições das jogadas
    if x < -100:
        col=0
    elif x>=-100 and x<=100:
        col=1
    elif x>100:
        col=2
    if y > 100:
        lin=0
    elif y<=100 and y>=-100:
        lin=1
    elif y<-100:
        lin=2    
    if rafa[lin][col]!= -1 and rafa[lin][col] !=1:
        rafa[3]+=1
        rafa[lin][col]=(-1)**rafa[3]
        draw(lin, col)
        if check():
            fim()
        #print(rafa, '---' , lin, col) #imprime as linhas e seus parametros.
    return True


def rafa_maker():#aonde cria o tabuleiro
    coord = [(-100,250,270),(100,250,270),(-250,100,0),(-250,-100,0)]
    for i in range(4):
        tup= coord[i]
        move(tup[0],tup[1],tup[2])
        turtle.forward(500)

def play(): 
    turtle.hideturtle()
    rafa_maker()#chama a função aonde cria as cordenados do tabuleiro
    window.onclick(decode)
    window.listen()

def loop(x,y): 
    if -50<x<50 and -5<y<45:
        turtle.clear()
        play()
    #else:
        #turtle.showturtle()
        #turtle.goto(x, y)

def move(x,y,beta):# move a caneta depois do click no star
    turtle.penup()
    turtle.goto(x,y)
    turtle.setheading(beta)
    turtle.pendown()
    return True

def begin(x,y): #Desenha o menu do jogo "STAR"
    r_x=random.randint(0,300)
    r_y=random.randint(0,300)
    turtle.clear()
    turtle.color('black')
    turtle.write('Star',False,'center',("Arial", 30, "normal"))
    move(-50,-5,90)
    turtle.forward(50)
    move(-50,-5,0)
    turtle.forward(100)
    move(50,-5,90)
    turtle.forward(50)
    move(-50,45,0)
    turtle.forward(100)
    move(r_x,r_y,0)#chama essa funcao, aonde verifica o click
    window.onclick(loop)#chama a função play jogo
    window.listen()

def tarta(): #ABRE A TURTLE
    turtle.speed(0)
    turtle.shape('turtle')
    turtle.hideturtle()
    return True

def main():
    tarta()
    begin(0,0)
    turtle.mainloop()
    
    return 'Fim'

#CODIGO PRINCIPAL, chamando as funções
if __name__ == '__main__':
	main()


#o codigo está disponivel no meu Github professor, se estiver duvida sob ele pode me mandar um e-mail
# pedindo explicaçao em alguma função que não intendeu !'''
