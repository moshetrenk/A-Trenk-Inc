var setStyles = function(d){
	document.getElementById('style' + d.id).setAttribute('list', d.value);
	document.getElementById('size'  + d.id).setAttribute('list', d.value + "Sizes");
	x = ("\#" + d.id)
	console.log('x = ' + x)
	console.log('d.id = ' + d.id)

	$(x).keypress(function (e) {
        	if ((e.which && e.which == 13) || (e.keyCode && e.keyCode == 13)){
			$("#" + d.id).next().focus()
			return false;
		}
	});
}

var g = function(d){	
	x = ("\#" + d.id)		
	console.log('x = ' + x)
	console.log('d.id = ' + d.id)

	$(x).keypress(function (e) {
        	if ((e.which && e.which == 13) || (e.keyCode && e.keyCode == 13)){
			$("#" + d.id).next().focus()
			return false;
		}
	});
}

var f = function(element){
	$(".q").keypress(function (e) {
        	if ((e.which && e.which == 13) || (e.keyCode && e.keyCode == 13)) {
			parentId = e.currentTarget.id;		
			newRowNum = parseInt(parentId.slice(1, parentId.length)) + 1;
            		$("#row"+newRowNum).html("<input style = 'margin: 0 4px 0 0' type = 'select' id = '" + newRowNum + "' name = 'brand" + newRowNum + "' list = 'brands' placeholder = 'Brand' onkeyup = 'setStyles(this)' onclick = 'setStyles(this)' onfocus = 'setStyles(this)' onselect = 'setStyles(this)' oninput = 'setStyles(this)'><input style = 'margin: 0 4px 0 0' type = 'select' id = 'style" + newRowNum + "' name = 'style" + newRowNum + "' placeholder = 'Style' onkeyup = 'g(this)'><input style = 'margin: 0 4px 0 0' type = 'select' id = 'size" + newRowNum + "' name = 'size" + newRowNum + "' placeholder = 'Size' onkeyup = 'g(this)'><input type = 'text' size = 4 id = 'q" + newRowNum + "' class = 'q' name = 'q" + newRowNum + "' placeholder = '#' onkeyup = 'f()'>");
            		document.getElementById(newRowNum).focus();
		return false;
        } else {
            	return true;
       	}});
}

var verify = function(element){
	console.log(element.value)
	var box = document.getElementById(element.id)

	var v = (/^\d+$/.test(box.value))
	console.log("v = " + v)
	if(!v){
		console.log("setValidity")
		box.setCustomValidity("Please Enter A Number")
		return;
	}
	else
	{
		console.log("removeValidity")
		box.setCustomValidity("")	
		return;
	}
}
