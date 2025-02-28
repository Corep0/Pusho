/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:55:27 by seruff            #+#    #+#             */
/*   Updated: 2025/02/26 14:51:42 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct		Element					// Structure des Elements associes a la liste
{
		int	value;
		int	index;					//Position dans la liste triee
		struct Element *next;
		struct Element *prev;
}			Element;
typedef struct 		List					// Structure de la liste
{
		Element	*first;
}			List;

int	ft_lstschr(List *list, int search);
void	move_in_b(List *list, List *temp, int median, int mid_median);
void	sort(List *list, List *temp);				// Trier la liste (suivant la taille)
void	sort_small(List *list);					// Trier une liste de 3 elements maximum
void	sort_four(List *list, List *temp);
void	sort_more(List *list, List *temp);

int	search_min(List *list);
int	search_max(List *list);

int	is_sorted(List *list);

int	peek_top_list(List *list);				// Donner l'element du haut de la liste
int	peek_bot_list(List *list);				// Donner l'element du bas de la liste
int	r_or_rr(List *list, int index);				// Calcule qu'elle operation est la meilleure entre Rotate et Reverse
void	move_to_top(List *list, int index, int ab);	// Deplacer l'element (index) au haut de la pile. ab = 1 for A ab = 2 for B

void	insert_sort(List *list);				// Trier la liste tempo

int	good_input(char **av);					// Check l'input(parsing)

int	fill_list_from_string(List *list, char **av);		// Remplir la liste des arguments
void	fill_list(List *list, int ac, char **av);		// Remplir la liste de la string
int	init(List *list, int ac, char **av);			// Initialiser, remplir la liste et retourner l'erreur

Element *create_element(int value);				// Creer l'element
List	*init_list();						// Initialiser la liste
List	*copy_list(List *list);					// Copy la liste principale
void	add_element(List *list, int value);			// Ajouter un element a la liste
int	count_elements(List *list);				// Compter le nombre d'element de la liste
void	print_list_index(List *list);
void	free_list(List *list);

void	push(List *src, List *dest);				// Push un element d'une liste src a dest
int	push_pa(List *src, List *dest);				// Push l'element de src a dest
int	push_pb(List *src, List *dest);				// Push l'element de dest a src

void	reverse(List *list);					// Reverse Operation
int	reverse_rra(List *listA);				// Reverse liste A
int	reverse_rrb(List *listB);				// Reverse liste B
int	reverse_rrr(List *listA, List *listB);			// Reverse liste A et liste B

void	rotate(List *list);					// Rotate Operation
int	rotate_ra(List *listA);					// Rotate liste A
int	rotate_rb(List *listB);					// Rotate liste B
int	rotate_rr(List *listA, List *listB);			// Rotate liste A et liste B

void	swap(List *list);					// Swap Operation
int	swap_sa(List *list);					// Swap A
int	swap_sb(List *list);					// Swap B
int	swap_ss(List *listA, List *listB);			// Swap A et Swap B

#endif
