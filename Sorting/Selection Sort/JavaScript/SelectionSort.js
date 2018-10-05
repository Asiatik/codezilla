var selectionSort = function(array) {
    var temp;

    for(var i=0; i<array.length; i++){
        var mi = i;
        
        for(var j = i + 1; j<array.length; j++) {
            if(array[j] < array[mi])
                mi = j;
        }

        temp = array[i];
        array[i] = array[mi];
        array[mi] = temp;
    }
};
