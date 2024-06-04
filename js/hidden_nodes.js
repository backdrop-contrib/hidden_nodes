(function ($) {

Backdrop.behaviors.hiddenNodeFieldsetSummaries = {
  attach: function (context) {
    $('fieldset#edit-hidden-nodes', context).backdropSetSummary(function (context) {
      var hid = $('input', context).is(':checked');

      return hid ?
        Backdrop.t('Hidden') :
        Backdrop.t('Normal (not hidden)'); 
    });
  }
};

})(jQuery); 
