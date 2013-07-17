<div class="block block-weibo-feed">
	<ul class="quicktabs unstyled clearfix">
		<li><a href="#feed-quicktab_0" data-toggle="tab">全部</a></li>
		<li class="active"><a href="#feed-quicktab_1" data-toggle="tab">我关注的</a></li>
		<li><a href="#feed-quicktab_2" data-toggle="tab">照片</a></li>
	</ul>
	<div class="block-content quicktab-content">
		<div class="quicktab-pane" id="feed-quicktab_0" style="display:none">全部</div>
		<div class="quicktab-pane active" id="feed-quicktab_1">
			<?php include("comments.php")?>
		</div>
		<div class="quicktab-pane" id="feed-quicktab_2" style="display:none">照片</div>
	</div>
</div>
