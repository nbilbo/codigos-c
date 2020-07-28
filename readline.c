/* Lêr um arquivo até que encontre uma quebra de linha ou o final do arquivo.
Retorna uma ponteiro de caractere onde o ultimo caractere é um '\0'. */
char *readline(FILE *fp){
    char caractere, *string;
    unsigned length;

    length=0;
    string=malloc(sizeof(char));
    
    //lendo o arquivo
    while(!feof(fp)){
        
        //obtendo o caractere
        caractere=fgetc(fp);
        
        //validando o caractere
        if(caractere != '\n' && caractere != -1){
            
            //atualizando a string
            length++;
            string=realloc(string, sizeof(char)*length);
            string[length-1]=caractere;
        }
        
        //caractere inválido.
        else break;
        
    //fim do laço
    }
    
    //adicioando o caractere '\0'.
    length++;
    string=realloc(string, sizeof(char)*length);
    string[length-1]='\0';
    
    //fim da função.
    return string;
};
