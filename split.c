
/*retorna um array de ponteiros p/ caracteres*/
char **split(char *string, char delimiter){
  char **result;
  unsigned count, index;
  
  count=0;
  /*percorrer toda a string*/
  while(*string){
    while(*string == delimiter) string++;
    /*se houver caracteres para serem lidos*/
    if(*string){
      count++;
      if(count==1) result=malloc(sizeof(char*));
      else result=realloc(result, sizeof(char*)*count);
      
      /*percorrer a string até encontrar o delimiter ou o final*/
      index=0;  
      while(*string && *string != delimiter){
        index++;
        if(index==1) result[count-1]=malloc(sizeof(char));
        else result[count-1]=realloc(result[count-1], sizeof(char)*index);
        result[count-1][index-1]=*string;
        string++;
      }
      /*adicionar um caractere '\0', no final da palavra*/
      index++;
      if(index==1) result[count-1]=malloc(sizeof(char));
      else result[count-1]=realloc(result[count-1], sizeof(char)*index);
      result[count-1][index-1]='\0';
    }
    
    /*se NÂO houver mais caracteres para serem lidos*/
    else break;
    
  }
  /*adicionando um ponteiro NULO no final do array */
  count++;
  if(count==1) result=malloc(sizeof(char*));
  else result=realloc(result, sizeof(char*)*count);
  result[count-1]=NULL;
  
  return result;
  
};