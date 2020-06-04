#include "../include/cub3d.h"

int		free_struct(t_info *info, int code_return)
{
	close(info->fd);
	if (info->map)
	{
		free(info->map);
		info->map = 0;
	}
	if (info->texture[0])
		free(info->texture[0]);
	if (info->texture[1])
		free(info->texture[1]);
	if (info->texture[2])
		free(info->texture[2]);
	if (info->texture[3])
		free(info->texture[3]);
	if (info->sprint)
		free(info->sprint);
	return (code_return);
}

void		freeContentNode(void *line)
{
	if ((char *)line)
	{
		free((char *)line);
		line = 0;
	}
}

int		freeAll(int codeReturn)
{
	close(g_info->fd);
	ft_lstclear(&g_info->begin, &freeContentNode);
	free_struct(g_info, codeReturn);
	if (g_win_mlx)
	{
		mlx_clear_window(g_mlx_ptr, g_win_mlx);
		mlx_destroy_window(g_mlx_ptr, g_win_mlx);
		if (g_img_ptr)
			mlx_destroy_image (g_mlx_ptr, g_img_ptr);
	}
	g_mlx_ptr = 0;
	g_win_mlx = 0;
	g_img_ptr = 0;
	g_info->begin = 0;
	return (codeReturn);
}
