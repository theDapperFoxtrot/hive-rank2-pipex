/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:43:05 by smishos           #+#    #+#             */
/*   Updated: 2024/08/09 19:14:21 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "printf.h"
#include <unistd.h>    // for write()
#include <string.h>    // for strlen() and strerror()
#include <errno.h>     // for errno
#include <stdlib.h>    // for exit()

void error_exit(char *message, int code)
{
    // Prepend custom message
    write(STDERR_FILENO, message, ft_strlen(message));

    // Add a separator (e.g., ": ")
    write(STDERR_FILENO, ": ", 2);

    // Write the system error message from strerror(errno)
    char *error_message = strerror(errno);
    write(STDERR_FILENO, error_message, ft_strlen(error_message));

    // Add a newline at the end
    write(STDERR_FILENO, "\n", 1);

    // Exit with the provided code
    exit(code);
}
