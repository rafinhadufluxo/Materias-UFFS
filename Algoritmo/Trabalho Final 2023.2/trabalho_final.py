#------------------------------------------------------------------------------#
import random
lista = []
# Classes
class Task():
  def __init__(self, id, tarefa, tempo,situ):
     self.id = id
     self.tarefa = tarefa
     self.tempo = tempo
     self.situ = situ

def adicionar_tarefa():
  comando = 0
  print("    Adicionar Tarefa")
  id = random.randint(100000,999999)#poderia criar uma variável limite e aumentar quando não tem mais id
  ids_anteriores = [i.id for i in lista]
  while id in ids_anteriores:
    id = random.randint(100000,999999)
  tarefa = input("Informe a tarefa a ser realizada: ")
  tempo = int(input("Informe o tempo limite em horas da tarefa: "))
  situ = False

  lista.append(Task(id,tarefa,tempo,situ))
  menu()


def lista_de_tarefas():
  comando = 0
  print("    Lista de Tarefas")
  if lista == []:
    print("A lista de tarefas está vazia")
    print("Retornando ao menu principal...\n\n")
  for i in lista:
    print(i.id, end=" ")
    if i.situ:
      print("C", end=" - ")
    else:
      print("P",end=" - ")
    print(f"{i.tempo}h", end=" | ")
    print(i.tarefa)
  print("\n Digite 1 para retornar ao menu principal")
  comando = input()
  if comando == 1:
    menu()
  else:
    while comando != 1:
      comando = input()
    menu()

def menu():
  print("Sistema de Gerenciamento de Tarefas v1.0\n")
  print("    Digite o número:")
  print("1 - Adicionar Tarefas")
  print("2 - Atualizar Tarfas")
  print("3 - Visualizar Todas as Tarefas")
  print("4 - Visualizar Tarefas Pendentes")
  print("5 - Visualizar Tarefas Finalizadas")
  print("")

  comando = int(input())
  if comando == 1:
    print()
    adicionar_tarefa()
  #elif comando == 2:
  #  atualizar_tarefa()
  elif comando == 3:
    visu_type = "T"
    print()
    lista_de_tarefas()
  elif comando == 4:
    visu_type = "P"
    print()
    lista_de_tarefas()
  elif comando == 5:
    visu_type = "C"
    print()
    lista_de_tarefas()

menu()

