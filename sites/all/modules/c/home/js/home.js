(function($) {

  var words = [];
  var current_word_index = 0;
  var current_pos = -1;

  // Display a new word
  function show_word() {
    console.log(words);
    console.log(words[current_word_index]);
  }

  Drupal.behaviors.muread_home = {
    attach: function(context, settings) {


      var theWord = settings.word_info.the_word;
      //console.log(theWord);
      words = settings.word_info.words;

      show_word();


      $('.keyboard-wrap .letter').on('click', function(e) {
        var letter = $(this).data('letter');
        console.log(letter);

        var text = new SpeechSynthesisUtterance('test');
        window.speechSynthesis.speak(text);
      })

      // Record hits
    /*
      $('.goto_origin').on('click', function() {
        var nid = $(this).data('nid');
        $.post('hit', {nid:nid}, function(result) {
        });
      });
      */

    }
  };

})(jQuery);
