<?php
function get_vocabulary($name=''){
	$voc = array(
		'subject'=>array('field'=>'field_subject',),
	);
	if(isset($voc[$name])){
		return $voc[$name];
	}
	else{
		return $voc;
	}
}