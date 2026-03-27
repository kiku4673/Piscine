/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:34:33 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:20:35 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


txt[i] = '\0';
return (txt);
}


int parse_dictionary_line(char *line, t_dict *dict)
{
int pos;
char *num;
char *txt;


pos = 0;
while (line[pos] && (IS_SPACE(line[pos]) || line[pos] == '\n'))
pos++;
if (!line[pos])
return (1);
if (line[pos] < '0' || line[pos] > '9')
return (0);
num = parse_number_str(line, &pos);
if (!num)
return (0);
while (line[pos] && IS_SPACE(line[pos]))
pos++;
if (line[pos] != ':')
return (free(num), 0);
pos++;
txt = parse_text(line, pos);
if (!txt)
return (free(num), 0);
if (!add_entry(dict, num, txt))
return (free(num), free(txt), 0);
free(num);
free(txt);
return (1);
}


int process_lines_from_content(char *content, t_dict *dict)
{
char *ls;
char *le;
int len;
int i;
char buf[1024];


ls = content;
while (*ls)
{
le = ls;
while (*le && *le != '\n')
le++;
len = le - ls;
if (len >= 1023)
return (0);
i = 0;
while (i < len)
{
buf[i] = ls[i];
i++;
}
buf[i] = '\0';
if (!parse_dictionary_line(buf, dict))
return (0);
if (*le == '\n')
le++;
ls = le;
}
return (1);
}


t_dict *load_dictionary(char *filename)
{
t_dict *dict;
char *content;


dict = (t_dict *)malloc(sizeof(t_dict));
if (!dict)
return (NULL);
dict->entries = NULL;
content = read_file(filename);
if (!content)
return (free(dict), NULL);
if (!process_lines_from_content(content, dict))
return (free(content), free_dictionary(dict), NULL), (t_dict *)NULL;
free(content);
return (dict);
}
