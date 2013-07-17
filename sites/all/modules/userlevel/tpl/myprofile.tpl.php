<div class="block block-user-profile">
  <div class="block-content pls">
    <div class="view view-playground-block view-id-playground_block view-display-id-block view-dom-id-f5ee300504a29175f826378c9ba37a6d">
      <div class="view-content">
        <div class="views-row views-row-1 views-row-odd views-row-first views-row-last">
    <div class="stbody">
  <div class="stimg stimgR"><div class="field-content">  <div class="user-picture">
    <a href="/users/<?php print $username;?>" title="View user profile."><?php print $user_picture;?></a>  </div>
</div></div>
  <div class="sttext">
    <h3 class="title">
        <?php print $username;?>
    </h3>
    <div class="user-atten clearfix">
      <div class="user-points">
        <i class="points-num"><?php print $points_str?></i>
      </div>
    </div>
    <?php print $userlevel;?>
  </div>
</div>
<!-- end user profile content -->


<div class="badgebox">
  <ul class="unstyled clearfix">
      <?php 
        foreach($userbadges as $each){
            print '<li><img title="'.$each['huamn_name'].'" src="'.$each['small_image'].'"></li>';
        }
      ?>
  </ul>
</div>
<!-- end badgebox content -->

<ul class="user-nums unstyled clearfix">
  <li><span class="field-content"><?php print $care_str;?></span></li>
</ul>
  </div>
    </div>
</div>  </div>
</div>