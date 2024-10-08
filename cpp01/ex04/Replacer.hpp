/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:48:10 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/24 14:48:19 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class Replacer
{
    private:
        std::string filename;
        std::string s1;
        std::string s2;
        std::string readFile();
        int     writeFile(std::string content);
        void    printError(std::string message);


    public:
        Replacer(std::string filename, std::string s1,  std::string s2);
        int replace();
};

#endif