int firstDuplicate(std::vector<int> a) {
  int duplicate = -1;
  int foundDuplicate = false;
  
  for(size_t i = 0; i < a.size(); i++){
    
    if(a[abs(a[i])-1] < 0 && !foundDuplicate){
      duplicate = abs(a[i]);
      foundDuplicate = true;
    } 
    if(a[abs(a[i])-1]>0){
      a[abs(a[i])-1] *= -1;
    }
    
   
  }
  
   return duplicate; 
    
  }