void array_remove (double *arr,size_t *pn, size_t pos){
    if(pos>=*pn)
     return;


    if(*pn==1)
     return;

     for (int i=pos;i<*pn;i++)
     arr[i]=arr[i+1];

     *pn = *pn - 1;

     
}