<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
function blog_publish_huandler($uid,$badge_conf){
    if(get_blog_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function blog_reply_huandler($uid,$badge_conf){
    if(get_comment_blog_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function blog_replyed_huandler($uid,$badge_conf){
    if(get_blog_commented_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function statuses_publish_huandler($uid,$badge_conf){
    if(get_statuses_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function statuses_publish_touser_huandler($uid,$badge_conf){
    if(get_statuses_touser_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function statuses_reply_huandler($uid,$badge_conf){
    if(get_statuses_comment_touser_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function statuses_like_huandler($uid,$badge_conf){
    if(get_statuses_like_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function blog_reply_vote_huandler($uid,$badge_conf){
    if(get_comment_blog_using_num($uid,$badge_conf['num'],$badge_conf['total'])){
        return true;
    }
    else{
        return false;
    }
}
function blog_publish_replyed_huandler($uid,$badge_conf){
    if(get_blogs_commented_num($uid,$badge_conf['num'],$badge_conf['reply'])){
        return true;
    }
    else{
        return false;
    }
}


////////////////////////////////////
function knowledge_reply_goodanswer_huandler($uid,$badge_conf){
    if(get_knowledge_terms_best_num($uid,$badge_conf['num'],$badge_conf['total'])){
        return true;
    }
    else{
        return false;
    }
}
function knowledge_best_reply_huandler($uid,$badge_conf){
    if(get_knowledge_best_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function knowledge_using_voted_huandler($uid,$badge_conf){
    if(get_knowledge_using_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function knowledge_replyed_huandler($uid,$badge_conf){
    if(get_knowledge_commented_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function knowledge_ask_reply_huandler($uid,$badge_conf){
    if(get_knowledge_publish_comment_num($uid,$badge_conf['tid'],$badge_conf['num'],$badge_conf['total'])){
        return true;
    }
    else{
        return false;
    }
}




/////////////////////////
function others_followed_huandler($uid,$badge_conf){
    if(get_followed_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
function others_follow_huandler($uid,$badge_conf){
    if(get_follow_num($uid,$badge_conf['num'])){
        return true;
    }
    else{
        return false;
    }
}
?>
