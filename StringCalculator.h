#include <string.h>



int temp_add(int *pos_arr, const char *inp, char delim, int pos_arr_index){
    int res = 0;
    int temp_res = 0;
    int start;
 //   char *temp = "";
    
    if(inp[0] == '/'){
        start = 1;
    }
    else
        start = 0;
    for(int i = start ; i < pos_arr_index ; ++i){
        if((pos_arr[i+1] - pos_arr[i]) >= 5)
            continue ;
        temp_res = 0;
        for(int j = pos_arr[i]+1; j < pos_arr[i+1]; ++j){
            temp_res = (temp_res * 10) + int(inp[j]);
        }
        res += temp_res;
    }
    return res;
}

int func(const char *inp, char delim){
    int pos_arr[strlen(inp)];
    int index = 0;
    int pos_arr_index = 0;
    pos_arr[pos_arr_index] = -1;
    ++pos_arr_index;
    while(inp[index] != '\0'){
        if (inp[index] == delim || inp[index] == '\n'){
            pos_arr[pos_arr_index] = index;
            ++pos_arr_index;
        }
    }
    pos_arr[pos_arr_index] = strlen(inp);
    return temp_add(pos_arr, inp, delim, pos_arr_index);
}

int add(const char *input){
    int res = 0;
    if (input == NULL || input[0] == '\0')
      return 0;
   if (input[0] == '/'){
       char delimiter = input[2];
       res = func(input, delimiter);
       return res;
   }
    res = func(input, ',');
    return res;
}
