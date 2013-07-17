
<?php include("html.php")?>
<body class="page-blog one-sidebar sidebar-second node-blog">
	<div class="wrapper">
		<?php include("header.php")?>
		<!-- end header content -->
		<div id="page">
			<div class="container clearfix">
				<div class="container-wrapper">
					<div class="container-inner">
						<div id="main-content" class="clearfix ptl">
							<div class="content fl">
								<?php include("tabs.php")?>
								<?php include("node.php")?>
							</div>	 
							<!-- end main contnet -->
							<div class="sidebar fl" id="second-sidebar">
								<?php include("add-new-blog.php")?>
								<?php include("block-blog-archive.php")?>
								<?php include("block-hot-blog.php")?>
							</div>
							<!-- end second sidebar content -->
						</div>
						<!-- end main content -->
						<div id="first-sidebar" class="sidebar clearfix">
							<!-- left side bar -->
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