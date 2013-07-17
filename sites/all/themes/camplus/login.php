<?php include("html.php")?>
<body class="not-logged-in page-user-login">
	<div class="page-login-wrapper">
		<h1 id="logo" class="pvxxl"><a href="#" title="home" rel="home" class="ir icon icon-login-logo">灵糧堂怡文中学</a></h1>
		<form action="" method="post" id="user-login">
			<div class="form-item">
				<label for="username" class="icon icon-user ir">username</label>
				<input type="text" class="form-text" id="username" name="name" required placeholder="WEB-Design">
			</div>
			<div class="form-item">
				<label for="password" class="icon icon-password ir">password</label>
				<input type="password" class="form-text" id="passowrd" name="password" requied placeholder="******">
			</div>
			<div class="form-action">
				<button class="btn btn-login" type="submit">Login</button>
			</div>
			<div class="form-item">
				<label class="checkbox">
					<input type="checkbox" class="form-checkbox">Remember Me
					<i class="icon icon-question ir"></i>
				</label>
				<div class="get-psw">Forgot Password <a href="#">Click here</a></div>
				<div class="register"><a href="#">Register</a></div>
			</div>
		</form>
	</div>	
</body>
</html>