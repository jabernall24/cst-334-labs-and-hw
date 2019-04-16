#! /usr/bin/env awk -f

/begin/ {
	for(i=0;i<1;i++){
		getline;
		if($0 ~ "A") counter++;
	}
}
END {
	print counter;
}