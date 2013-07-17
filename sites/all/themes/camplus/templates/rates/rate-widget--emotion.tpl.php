<?php
/**
 * @file
 * Rate widget theme
 */
?>
<ul class="unstyled clearfix">
  <?php foreach($links as $link): ?>
    <li>
      <span class="num"><?php print t($results['options'][$link['value']]); ?></span>
      <span class="rate-out"><span class="rate-inner" style="height:<?php print $results['options'][$link['value']]; ?>%;"></span></span>
      <a href="<?php print $link['href']; ?>" rel="nofollow" class="title rate-button"><i class="icon ir icon-mood-<?php print $link['value']; ?>"></i><?php print t($link['text']); ?></a>
    </li>
  <?php endforeach; ?>
</ul>
<?php
if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
