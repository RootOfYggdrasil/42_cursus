/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:37:56 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 15:25:49 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

/* List declaretion */
typedef struct s_list
{
	int				value;
	int				i;
	struct s_list	*next;
}				t_list;

/*
	check.c
*/
void	ft_check_args(int ac, char **av);
void	stderr_exit(const char *s);
int		ft_isnum(char *num);
/*
	sort_utils.c
*/
int		is_sorted(t_list **l);
t_list	*ft_min(t_list **l);
long	ft_atoi_long(const char *nptr);
/*
	list_base.c
*/
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **l, t_list *new);
void	ft_lstadd_front(t_list **l, t_list *new_head);
t_list	*ft_lstlast(t_list *head);
int		ft_lstsize(t_list *lst);
/*
	list_utils.c
*/
int		ft_lst_distance(t_list **l, int n);
void	ft_assign_index(t_list **l);
void	ft_init_list(t_list **l_a, int ac, char **av);
void	ft_free(char **str);
void	ft_free_list(t_list **l);
/*
	sort.c
*/
void	ft_sort(t_list **l_a, t_list **l_b);

/*
	rotation.c
*/
int		ft_rotate(t_list **l);
int		ft_rab(t_list **l_a, char op);
int		ft_reverse_rotate(t_list **l);
int		ft_rrab(t_list **l_a, char op);
/*
	swap_push.c
*/
int		ft_sab(t_list **l, char op);
int		ft_pab(t_list **l_a, t_list **l_b, char op);
/*
	list_base.c
*/

#endif
