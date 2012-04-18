(function ($) {
  // define function for hidden_nodes operation
  Drupal.outline_designer_ops.hidden_nodes = function() {
    $(".od_submit_button").val('Submit');
    // set default state based on whats loaded
    if ($("#node-" + Drupal.settings.outline_designer.activeNid +"-icon").parent().parent().hasClass('node_is_hidden')) {
      $('#od_hidden_nodes_status').attr('checked','checked')
    }
    else {
      $('#od_hidden_nodes_status').removeAttr('checked')
    }
    // function call
    Drupal.outline_designer.render_popup(true);
  };
  // submit handler
  Drupal.outline_designer_ops.hidden_nodes_submit = function() {
    var multiple = $('#od_hidden_nodes_multiple:checked').length;
    var hide_status = $('#od_hidden_nodes_status:checked').length;
    $.ajax({
      type: "POST",
      url: Drupal.settings.outline_designer.ajaxPath + Drupal.settings.outline_designer.token +"/hidden_nodes/" + Drupal.settings.outline_designer.activeNid + "/" + multiple +"/"+ hide_status,
      success: function(msg){
        $("#reload_table").trigger('change');
        if(msg == 0) {
          Drupal.outline_designer.growl("You don't have sufficient permissions!");
        }
        else {
          Drupal.outline_designer.growl(msg);
        }
      }
    });
  };
  // reset handler
  Drupal.outline_designer_ops.hidden_nodes_reset = function() {
    $("#od_hidden_nodes_multiple").attr("checked", true);
  };
})(jQuery);