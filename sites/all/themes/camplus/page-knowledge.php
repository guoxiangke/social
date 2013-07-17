<?php include("html.php") ?>
<body class="page-knowledge sidebar-first">
	<div class="wrapper">
		<?php include("header.php") ?>
		<!-- end header content -->
		<div id="page">
			<div class="container clearfix">
				<div class="container-wrapper">
					<div class="container-inner">
						<div id="main-content" class="clearfix ptl">
							<div class="content fl">
								<?php include("node-question-form.php") ?>
							</div>	 
							<!-- end main contnet -->							
						</div>
						<!-- end main content -->
						<div id="first-sidebar" class="sidebar clearfix ptl">
							<?php include("knowledge-search.php") ?>
							<?php include("hot-question.php") ?>
						</div>					
						<!-- end first-sidebar content -->
					</div>
				</div>				
			</div>
		</div>
		<!-- end page content -->
		<?php include("footer.php") ?>
		<!-- end footer content -->
	</div>	
</body>
</html>