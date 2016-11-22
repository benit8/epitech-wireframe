function table(w, h){
	for (i = 0; i < (w * h); i++){
		$('output').append(" ".repeat(4 - i.toString().length));
		$('output').append('<span id="' + i + '">' + i + "</span>");

		if (i >= (w * h) - w){
			$('#' + i).addClass('last');
		}

		if (i % w == w - 1 && i != 0){
			$('output').append('<br>');
			$('#' + i).addClass('border');
		} else{
			$('output').append(' ');
		}
	}
}

table(5, 5);
$('input').on('change', function(){
	$('output').empty();
	table($('#width').val(), $('#height').val());
})