<?php

    function binarySearch($list, $item){
        $leftIndex = 0;
        $rightIndex = sizeof($list);
        
        while($leftIndex <= $rightIndex){
            $middleIndex = intdiv(($leftIndex + $rightIndex), 2);
            
            if($list[$middleIndex] < $item){
                $leftIndex = $middleIndex + 1;
            }
            else if ($list[$middleIndex] > $item){
                $rightIndex = $middleIndex - 1;
            }
            else{
                return $middleIndex;
            }
        }
        return -1;
    }
    
    // Simple demonstration of the function
    $array = array(1, 2, 4, 5, 6, 8, 9, 10, 14);
    echo binarySearch($array, 8);
?>
