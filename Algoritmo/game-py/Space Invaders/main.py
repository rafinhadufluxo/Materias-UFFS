
import turtle
import os
import math
import random

#Configure a tela
wn = turtle.Screen()
wn.bgcolor("black")
wn.title("Space Invaders")
wn.bgpic("space_invaders_background.gif")

#Registro da tela
turtle.register_shape("invader.gif")
turtle.register_shape("player.gif")

#Desenhando a borda
border_pen = turtle.Turtle()
border_pen.speed(0)
border_pen.color("white")
border_pen.penup()
border_pen.setposition(-300,-300)
border_pen.pendown()
border_pen.pensize(3)
for side in range(4):
	border_pen.fd(600)
	border_pen.lt(90)
border_pen.hideturtle()	

#Defina a pontuação como do jogador
score = 0

#Desenhando a pontuação
score_pen = turtle.Turtle()
score_pen.speed(0)
score_pen.color("white")
score_pen.penup()
score_pen.setposition(-290, 280)
scorestring = "Score: %s" %score
score_pen.write(scorestring, False, align="left", font=("Arial", 14, "normal"))
score_pen.hideturtle()

#Cria o jogador principal
player = turtle.Turtle()
player.color("blue")
player.shape("player.gif")
player.penup()
player.speed(0)
player.setposition(0, -250)
player.setheading(90)

playerspeed = 15

#Escolha um número de inimigos
number_of_enemies = 5
#Cria uma lista vazia de inimigos
enemies = []

#Adiciona inimigos à lista
for i in range(number_of_enemies):
	#Cria o inimigo
	enemies.append(turtle.Turtle())

for enemy in enemies:
	enemy.color("red")
	enemy.shape("invader.gif")
	enemy.penup()
	enemy.speed(0)
	x = random.randint(-200, 200)
	y = random.randint(100, 250)
	enemy.setposition(x, y)

enemyspeed = 2


#Crie o marcador do jogador
bullet = turtle.Turtle()
bullet.color("yellow")
bullet.shape("triangle")
bullet.penup()
bullet.speed(0)
bullet.setheading(90)
bullet.shapesize(0.5, 0.5)
bullet.hideturtle()

bulletspeed = 20

#pronto - pronto para disparar
bulletstate = "ready"


#Movendo o jogador para a esquerda e direita
def move_left():
	x = player.xcor()
	x -= playerspeed
	if x < -280:
		x = - 280
	player.setx(x)
	
def move_right():
	x = player.xcor()
	x += playerspeed
	if x > 280:
		x = 280
	player.setx(x)
	
def fire_bullet():
	#Declarar o bulletstate como global se precisar ser alterado
	global bulletstate
	if bulletstate == "ready":
		os.system("afplay laser.wav&")
		bulletstate = "fire"
		#Movendo a bala para o logo acima do jogador
		x = player.xcor()
		y = player.ycor() + 10
		bullet.setposition(x, y)
		bullet.showturtle()

def isCollision(t1, t2):
	distance = math.sqrt(math.pow(t1.xcor()-t2.xcor(),2)+math.pow(t1.ycor()-t2.ycor(),2))
	if distance < 15:
		return True
	else:
		return False
#Criar ligações de teclado (setas melhor dizendo)
turtle.listen()
turtle.onkey(move_left, "Left")
turtle.onkey(move_right, "Right")
turtle.onkey(fire_bullet, "space")

#Loop do jogo principal
while True:
	
	for enemy in enemies:
		#Movendo o inimigo
		x = enemy.xcor()
		x += enemyspeed
		enemy.setx(x)

		#Movendo o inimigo para trás e para baixo


		if enemy.xcor() > 280:
			#Mover todos os inimigos para baixo
			for e in enemies:
				y = e.ycor()
				y -= 40
				e.sety(y)
			#Mudando a direção do inimigo


			enemyspeed *= -1
		
		if enemy.xcor() < -280:
			#Movendo todos os inimigos para baixo
			for e in enemies:
				y = e.ycor()
				y -= 40
				e.sety(y)
			#Mudando a direção do inimigo
			enemyspeed *= -1
			
		#Verificando se há uma colisão entre a bala e o inimigo
		if isCollision(bullet, enemy):
			os.system("afplay explosion.wav&")
			#Redefinir o jogador ( ou seja o marcador)
			bullet.hideturtle()
			bulletstate = "ready"
			bullet.setposition(0, -400)
			#Redefinir o inimigo
			x = random.randint(-200, 200)
			y = random.randint(100, 250)
			enemy.setposition(x, y)
			#Atualizando a pontuação
			score += 10
			scorestring = "Score: %s" %score
			score_pen.clear()
			score_pen.write(scorestring, False, align="left", font=("Arial", 14, "normal"))
		
		if isCollision(player, enemy):
			os.system("afplay explosion.wav&")
			player.hideturtle()
			enemy.hideturtle()
			print ("Game Over")
			break

		
	#Movendo a bala
	if bulletstate == "fire":
		y = bullet.ycor()
		y += bulletspeed
		bullet.sety(y)
	
	#Verifique se o marcador foi para o topo (caso o jogador)
	if bullet.ycor() > 275:
		bullet.hideturtle()
		bulletstate = "ready"


delay = raw_input("Press enter to finsh.")


#SOS de explicao ....
#caso não dê certo o raw_input não funcionar a sua maquina por versão do py, troque apenas para o delay = input("Press enter to finsh.")
