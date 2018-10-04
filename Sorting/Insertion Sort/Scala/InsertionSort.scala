def insertionsort(myList: Array[Int]): Unit = {

    for(i <- 1 to myList.length-1){
        var j = i-1
        var x = myList(i)

        while(j >= 0 && myList(j) > x){
            myList(j+1) = myList(j)
            j = j-1
        }
        myList(j+1) = x
    }
}


var myList = Array[Int](44,2,34,9,7,5,8,3,1,5)

insertionsort(myList)
myList.foreach(println)
