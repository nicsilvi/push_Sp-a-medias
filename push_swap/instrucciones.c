/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrucciones.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:43 by smercado          #+#    #+#             */
/*   Updated: 2024/10/30 12:25:42 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

main()
{
	a
	b
	check_args(argv, argc)
	init(a)
	choose_sortation(&a, &b)
}

check_args()
{
	str_to_char **
	is_digit
	isnt_repeat
	is_intlimit	
}

init(a)
{
	nums ->add_bottom
	indexs
	pos-1
	cost-1
	target-1
}

choose_sortation()
{
	size == 2
		sa
	size == 3
		sort_three(a)
	size > 3
		algorithm
}

algorithm()
{
	move a to b (todo menos 3, pasar < que size/2 antes)
	sort_three(a)
	ver posiciones actuales
	calcular_objetivo(parejas)
	calcular_costes
	mover_a
	mover_b
	mover_all
	ajustar_a
}

calcular_objetivo()
{
	(para cada b) take_b y buscar la pos en a
		se busca el 1r num mas peque que en b.
		si no hay -> es el mas grande pq es el final.
}

calcular costes:
{
	a partir de la media, ver cada objetivo en b y cuanto cuesta moverlo arriba para para a
		+ subir a objetivo de b
	coste_a
	coste_b
	ambos (si estan en la misma direccion)
}

mover all()
{
	while()
	escoger la pareja mas barata y mover
}

ajustar_a
{
	subir el menor arriba. 
}
