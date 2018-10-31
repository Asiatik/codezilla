function bubbleSort(haystack, n) {
	if (typeof haystack === 'undefined' || !haystack.length || haystack.length <= 0) {
		return [];
	}
	
	n = n || haystack.length;
	
	var temp = 0;
	var i = 0;
	var j = 0;
	
	for(i=0; i < n; i++) {
		for (j=0; j < n; j++) {
			temp = haystack[(j-1)];
			if (temp > haystack[j]) {
				haystack[(j-1)] = haystack[j];
				haystack[j] = temp;
			}
		}
	}

	return haystack;
} 
