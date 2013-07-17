<?php
/*
*doctype file: html.php
*header content: header.php
*footer content: footer.php
+==============================+
*page login: login.php
*/
?>

<?php include("html.php")?>
<body class="front two-sidebar">
	<div class="wrapper">
		<?php include("header.php")?>
		<!-- end header content -->
		<div id="page">
			<div class="container clearfix">
				<div class="container-wrapper">
					<div class="container-inner">
						<div id="main-content" class="clearfix ptl">
							<div class="content fl">
								<?php include("block-weibo.php")?>
								<?php include("weibo-feed.php")?>
							</div>	 
							<!-- end main contnet -->
							<div class="sidebar fl" id="second-sidebar">
								<?php include("daily-quote.php")?>
								<?php include("interest-people.php")?>
							</div>
							<!-- end second sidebar content -->
						</div>
						<!-- end main content -->
						<div id="first-sidebar" class="sidebar clearfix ptl">
							<?php include("user-profile.php")?>
							<?php include("ranking.php")?>
						</div>					
						<!-- end first-sidebar content -->
					</div>
				</div>				
			</div>
		</div>
		<!-- end page content -->
		<?php include("footer.php")?>
		<!-- end footer content -->
	</div>	
</body>
</html>