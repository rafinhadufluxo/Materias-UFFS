#Python 2

import Tkinter
import tkMessageBox
import random

#Create root window
root = Tkinter.Tk()

#Change root window background color
root.configure(bg="white")

#Change the title
root.title("My Super To Do List")

#Change the window size
root.geometry("325x275")

#Create an empty list
tasks = []

#For testing purposes use a default list
tasks = ["Call mom", "Buy a guitar", "Eat sushi"]

#Create functions

def update_listbox():
	#Clear the current list	
	clear_listbox()
	#Populate the listbox
	for task in tasks:
		lb_tasks.insert("end", task)

def clear_listbox():
	lb_tasks.delete(0, "end")

def add_task():
	#Get the task to add
	task = txt_input.get()
	#Make sure the task is not empty
	if task !="":
		#Append to the list
		tasks.append(task)
		#Update the listbox
		update_listbox()
	else:
		tkMessageBox.showwarning("Warning", "You need to enter a task.")
	txt_input.delete(0, "end")
		
def del_all():
	confirmed = tkMessageBox.askyesno("Please Confirm", "Do you really want to delete all?")
	if confirmed == True:
		#Since we are changing the list, it needs to be global.
		global tasks
		#Clear the tasks list
		tasks = []
		#Update the listbox
		update_listbox()

def del_one():
	#Get the text of the currently selected item
	task = lb_tasks.get("active")
	#Confirm it is in the list
	if task in tasks:
		tasks.remove(task)
	#Update the listbox
	update_listbox()

def sort_asc():
	#Sort the list
	tasks.sort()
	#Update the listbox
	update_listbox()

def sort_desc():
	#Sort the list
	tasks.sort()
	#Reverse the list
	tasks.reverse()
	#Update the listbox
	update_listbox()

def choose_random():
	#Choose a random task
	task = random.choice(tasks)
	#Update the display label
	lbl_display["text"]=task

def show_number_of_tasks():
	#Get the numbers of tasks
	number_of_tasks = len(tasks)
	#Create and format the message
	msg = "Number of tasks: %s" %number_of_tasks
	#Display the message
	lbl_display["text"]=msg


lbl_title = Tkinter.Label(root, text="To-Do-List", bg="white")
lbl_title.grid(row=0,column=0)

lbl_display = Tkinter.Label(root, text="", bg="white")
lbl_display.grid(row=0,column=1)

txt_input = Tkinter.Entry(root, width=15)
txt_input.grid(row=1,column=1)

btn_add_task = Tkinter.Button(root, text="Add task", fg="green", bg="white", command=add_task)
btn_add_task.grid(row=1,column=0)

btn_del_all = Tkinter.Button(root, text="Delete All", fg="green", bg="white", command=del_all)
btn_del_all.grid(row=2,column=0)

btn_del_one = Tkinter.Button(root, text="Delete", fg="green", bg="white", command=del_one)
btn_del_one.grid(row=3,column=0)

btn_sort_asc = Tkinter.Button(root, text="Sort (ASC)", fg="green", bg="white", command=sort_asc)
btn_sort_asc.grid(row=4,column=0)

btn_sort_desc = Tkinter.Button(root, text="Sort (DESC)", fg="green", bg="white", command=sort_desc)
btn_sort_desc.grid(row=5,column=0)

btn_choose_random = Tkinter.Button(root, text="Choose Random", fg="green", bg="white", command=choose_random)
btn_choose_random.grid(row=6,column=0)

btn_number_of_tasks = Tkinter.Button(root, text="Number of Tasks", fg="green", bg="white", command=show_number_of_tasks)
btn_number_of_tasks.grid(row=7,column=0)

btn_exit = Tkinter.Button(root, text="Exit", fg="green", bg="white", command=exit)
btn_exit.grid(row=8,column=0)

lb_tasks = Tkinter.Listbox(root)
lb_tasks.grid(row=2,column=1, rowspan=7)

#Start the main events loop
root.mainloop()


#ordenando em uma lista nomes, em ordem crescente e decrecente ainda
