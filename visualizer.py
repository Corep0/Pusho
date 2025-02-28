import subprocess
import tkinter as tk
from tkinter import messagebox
import random

def run_push_swap(numbers):
    result = []
    try:
        # Lance push_swap et récupère la sortie
        process = subprocess.Popen(['./push_swap'] + numbers, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        try:
            stdout, stderr = process.communicate(timeout=10)  # Timeout de 10 secondes
        except subprocess.TimeoutExpired:
            process.kill()
            stdout, stderr = process.communicate()
            print("push_swap a pris trop de temps et a été interrompu.")
        
        if process.returncode != 0:  # Vérifie s'il y a eu une erreur
            print("Erreur lors de l'exécution de push_swap:", stderr.decode())
            return []
        
        result = stdout.decode().strip().split("\n")
        return result
    except Exception as e:
        print("Erreur de sous-processus:", e)
        return []

def apply_operation(operation):
    global stack_a, stack_b
    if operation == "sa":
        stack_a[0], stack_a[1] = stack_a[1], stack_a[0]  # Swap de la pile A
    elif operation == "sb":
        stack_b[0], stack_b[1] = stack_b[1], stack_b[0]  # Swap de la pile B
    elif operation == "pa" and stack_b:
        stack_a.insert(0, stack_b.pop(0))  # Push de B vers A
    elif operation == "pb" and stack_a:
        stack_b.insert(0, stack_a.pop(0))  # Push de A vers B
    elif operation == "ra" and stack_a:
        stack_a.append(stack_a.pop(0))  # Rotation de la pile A
    elif operation == "rb" and stack_b:
        stack_b.append(stack_b.pop(0))  # Rotation de la pile B
    elif operation == "rra" and stack_a:
        stack_a.insert(0, stack_a.pop())  # Rotation inverse de la pile A
    elif operation == "rrb" and stack_b:
        stack_b.insert(0, stack_b.pop())  # Rotation inverse de la pile B

def update_visualization(steps):
    line_count = 0  # Initialisation du compteur de lignes
    for step in steps:
        operations_label.config(text=f"Opération en cours: {step}")
        
        apply_operation(step)
        
        stack_a_label.config(text="Pile A:\n" + '\n'.join(map(str, stack_a)))
        stack_b_label.config(text="Pile B:\n" + '\n'.join(map(str, stack_b)))
        
        line_count += 1
        line_count_label.config(text=f"Lignes traitées: {line_count}")
        
        root.update()
        root.after(1)  # Attendre 500ms entre chaque étape

numbers = random.sample(range(0, 101), 100)  # On utilise des nombres de 1 à 100 pour la simplicité
#numbers = [ 0, -1, 2, 3, 4, 5, 6, 1]
numbers_str = list(map(str, numbers))  # Conversion des nombres en chaînes

stack_a = numbers.copy()
stack_b = []

steps = run_push_swap(numbers_str)

if not steps:
    print("Aucune opération récupérée de push_swap, vérifie ton programme push_swap.")

root = tk.Tk()
root.title("Visualizer Push_Swap avec les commandes ra, rb, rra, rrb")

stack_a_label = tk.Label(root, text="Pile A:\n" + '\n'.join(map(str, stack_a)), font=("Helvetica", 12))
stack_a_label.pack(side="left", padx=10, pady=10)

stack_b_label = tk.Label(root, text="Pile B:\n" + '\n'.join(map(str, stack_b)), font=("Helvetica", 12))
stack_b_label.pack(side="right", padx=10, pady=10)

operations_label = tk.Label(root, text="Opération en cours: ", font=("Helvetica", 12))
operations_label.pack(pady=10)

line_count_label = tk.Label(root, text="Lignes traitées: 0", font=("Helvetica", 12))
line_count_label.pack(pady=10)

start_button = tk.Button(root, text="Démarrer Visualisation", command=lambda: update_visualization(steps), font=("Helvetica", 12))
start_button.pack(pady=20)

root.mainloop()

