/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bmp_reader.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 14:07:23 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 22:53:37 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** Opens "path" bmp file and fills the arguments with :
** - t : table containing the RGBA pixels of the image
** - h : height of the image
** - w : width of the image
**
** Note : t[h][w] = RGBA pixela
**
** DISCLAIMER : This program being done for educational purposes only,
** it does NOT supports all BMP formats, and therefore
** can fail to open and read true BMP files for many reasons.
** Unsupported features :
** - Many DIB headers
** - Extra bit masks
** - Color table
** - ICC color profile
*/




//TODO :
// Codes d'erreur a revoir
// Disclaimer a revoir, la partie DIB sera surement completement ignoree ?



#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


int get_bmp_file(char *path, int ***t, int *h, int *w)
{
	int fd;
	int res;
	char buf[4];

	/* FILE OPEN */
	fd = open(path, O_RDONLY);
	if (file < 0)
		return (-1); // Failed to open file
	
	/* READ HEADER */
	//res = read(fd, buf, 2);
	if (read(fd, buf, 2) < 2)
		return (-1); // Failed to read 
	if (buf[0] != 'B' && buf[1] != 'M')
		return (-1); // FILE IS NOT BMP OR NOT SUPPORTED
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read
	if (read(fd, buf, 2) < 2 && read(fd, buf, 2) < 2)
		return (-1); // Failed to read
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read
	// ICI BUF = ADDRESSE DE DEPART DU VRAI BITMAP
	
	/* READ DIB HEADER */
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read // ICI BUF = TAILLE DE L'ENTETE DE L'IMAGE
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read // ICI BUF = width de l'image
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read // ICI BUF = height de l'image
	if (read(fd, buf, 2) < 2)
		return (-1); // Failed to read -> Useless read : "The number of color planes, must be 1"
	if (read(fd, buf, 2) < 2)
		return (-1); // Failed to read // ICI BUF = nb de bits par pixel (quitter si < 32 ?)
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read // ICI BUF = méthode de compression 
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read // ICI BUF = taille image
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read : Width px/m
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read : Height px/m
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read : Palette number of colors > dafuq is that ?
	if (read(fd, buf, 4) < 4)
		return (-1); // Failed to read : Important palette colors > dafuq is that ?

	/************** DECOMPRESSION ? *************/

	/* PIXELS READER */
	
}
